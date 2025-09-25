# IWSManSession::put_BatchItems

## Description

Sets and gets the number of items in each enumeration batch. This value cannot be changed during an enumeration. The resource provider may set a limit.

This property is read/write.

## Parameters

## Remarks

This is an optimization feature that controls how often network calls are made between the client and the server. Currently, it is used only for enumerations. For more information about enumerating resources, see [IWSManEnumerator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanenumerator).

## See also

[IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession)

[Session.BatchItems](https://learn.microsoft.com/windows/desktop/WinRM/session-batchitems)