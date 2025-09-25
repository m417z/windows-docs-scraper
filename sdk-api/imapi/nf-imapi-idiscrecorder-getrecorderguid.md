# IDiscRecorder::GetRecorderGUID

## Description

Retrieves the GUID of the physical disc recorder currently associated with the recorder object.

## Parameters

### `pbyUniqueID` [in]

Pointer to a GUID buffer to be filled in with this recorder's current GUID information. To query the required buffer size, use **NULL**.

### `ulBufferSize` [in]

Size of the GUID buffer. If *pbyUniqueID* is **NULL**, this parameter must be zero.

### `pulReturnSizeRequired` [out]

Size of the GUID information.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder)