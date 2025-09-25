# MI_SubscriptionDeliveryOptions_SetBookmark function

## Description

Sets a bookmark for subscription indication delivery.

## Parameters

### `self` [in, out]

A pointer to a [MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions) structure.

### `value`

A null-terminated string that represents the bookmark that was retrieved from a previous indication result delivery, or one of two constants (**MI_SUBSCRIBE_BOOKMARK_OLDEST** or **MI_SUBSCRIBE_BOOKMARK_NEWEST**) that specify when a subscription should start.

#### MI_SUBSCRIBE_BOOKMARK_OLDEST (L"MI_SUBSCRIBE_BOOKMARK_OLDEST")

Start the subscription from the earliest possible indication.

#### MI_SUBSCRIBE_BOOKMARK_NEWEST (L"MI_SUBSCRIBE_BOOKMARK_NEWEST")

Start the subscription from this point.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

This function tells the server that bookmarks are required, and (if supported) it should return bookmarks with the indication results.

## See also

[MI_SubscriptionDeliveryOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_subscriptiondeliveryoptions)

[MI_SubscriptionDeliveryOptions_GetBookmark](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_subscriptiondeliveryoptions_getbookmark)