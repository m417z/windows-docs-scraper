# DWriteEngine2Events::Update

## Description

Implement this method to receive progress notification of the current write operation.

## Parameters

### `object` [in]

The [IWriteEngine2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2) interface that initiated the write operation.

This parameter is a **MsftWriteEngine2** object in script.

### `progress` [in]

An [IWriteEngine2EventArgs](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2eventargs) interface that you use to determine the progress of the write operation.

This parameter is a **MsftWriteEngine2** object in script.

## Return value

Return values are ignored.

## Remarks

Notifications are sent in response to calling the [IWriteEngine2::WriteSection](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-writesection) method.

Notification is sent:

* Once before the operation begins
* Every 0.5 seconds during the write operation
* Once after the operation completes

To stop the write process, call the [IWriteEngine2::CancelWrite](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-cancelwrite) method.

## See also

[DWriteEngine2Events](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-dwriteengine2events)

[IWriteEngine2::WriteSection](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-writesection)

[IWriteEngine2EventArgs](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2eventargs)