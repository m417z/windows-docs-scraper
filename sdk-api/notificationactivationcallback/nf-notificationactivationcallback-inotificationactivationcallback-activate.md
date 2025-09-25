# INotificationActivationCallback::Activate

## Description

Called when a user interacts with a toast in the action center.

## Parameters

### `appUserModelId` [in]

The unique identifier representing your app to the notification platform.

### `invokedArgs` [in]

Arguments from the invoked button. **NULL** if the toast indicates the default activation and no launch arguments were specified in the XML payload.

### `data` [in]

The data from the input elements available on the notification toast.

### `count` [in]

The number of *data* elements.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In order for your app to respond to toasts in the action center, you need to override this method in your app. You also will need to create a shortcut on the start menu. For more information about how to respond to activation notifications, see [Respond to toast activations](https://learn.microsoft.com/previous-versions/windows/desktop/win32_tile_badge_notif/respond-to-toast-activations).

If your application uses non-interactive toasts, you can respond to those without using *invokedArgs* or *data*.

If you return a failure code, the activation will fail and the user can try again to activate your app.

## See also

[INotificationActivationCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/notificationactivationcallback/nn-notificationactivationcallback-inotificationactivationcallback)

[Respond to toast activations](https://learn.microsoft.com/previous-versions/windows/desktop/win32_tile_badge_notif/respond-to-toast-activations)