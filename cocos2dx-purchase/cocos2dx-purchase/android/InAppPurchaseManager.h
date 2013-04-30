#ifndef INAPPPURCHASEMANAGER_H
#define INAPPPURCHASEMANAGER_H
//
//  InAppPurchaseManager.h
//  cocos2dx-purchase
//
//  Created by Yohei Okaya on 2013/03/14.
//  Copyright (c) 2013 , Yohei Okaya All rights reserved.
//

#include "cocos2d.h"
#include "PurchaseMacros.h"

using namespace std;

NS_CC_PURCHASE_BEGIN

typedef enum {
    SKPaymentTransactionStatePurchased,     // Transaction is in queue, user has been charged.  Client should complete the transaction.
    SKPaymentTransactionStateFailed,        // Transaction was cancelled or failed before being added to the server queue.
    SKPaymentTransactionStateRestored       // Transaction was restored from user's purchase history.  Client should complete the transaction.
} SKPaymentTransactionState;

class InAppPurchaseManager
: public CCObject
//, public SKProductsRequestDelegate
//, public SKPaymentTransactionObserver
{
public:
    static InAppPurchaseManager& getInstance();
    bool purchase(CCString * productId, int price);
    void consume(const char* purchaseData, const char* signature);
    bool paymentTransaction(const char* productId, const char* purchaseData, const char* signature, int purchaseState);

protected:

    static void BillingInitHandler(int error);
    static void PurchasedHandler(int result);
    static void ConsumeHandler(int result);

private:
    InAppPurchaseManager() {};
    ~InAppPurchaseManager() {};

    static bool m_init;

    InAppPurchaseManager(const InAppPurchaseManager&);
    InAppPurchaseManager& operator=(const InAppPurchaseManager&);
};

NS_CC_PURCHASE_END

#endif

