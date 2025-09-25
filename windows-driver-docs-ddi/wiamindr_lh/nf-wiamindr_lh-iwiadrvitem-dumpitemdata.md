## Description

The **IWiaDrvItem::DumpItemData** method dumps private data associated with an **IWiaDrvItem** item into an allocated private buffer.

## Parameters

### `__MIDL__IWiaDrvItem0015`

*bstrDrvItemData* [out, optional]

Points to an allocated buffer that will receive the **IWiaDrvItem** data.

## Return value

If the method succeeds, it returns **S_OK**. If the method fails the buffer allocation, it returns **E_OUTOFMEMORY**. If the method fails for another reason, it returns a standard COM error code.

## Remarks

This method is provided for Microsoft internal debugging only. It will return **E_NOTIMPL** on the release operating system.