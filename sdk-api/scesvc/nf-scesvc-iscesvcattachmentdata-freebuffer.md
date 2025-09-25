# ISceSvcAttachmentData::FreeBuffer

## Description

The **FreeBuffer** method frees memory allocated by the Security Configuration snap-in.

## Parameters

### `pvData` [in]

Void pointer to the buffer to be freed.

## Return value

The return value is an HRESULT. A value of S_OK indicates the method was successful.

## Remarks

You should call this method to free the data buffer returned by
[ISceSvcAttachmentData::GetData](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentdata-getdata).

## See also

[ISceSvcAttachmentData](https://learn.microsoft.com/windows/desktop/api/scesvc/nn-scesvc-iscesvcattachmentdata)

[ISceSvcAttachmentData::GetData](https://learn.microsoft.com/windows/desktop/api/scesvc/nf-scesvc-iscesvcattachmentdata-getdata)