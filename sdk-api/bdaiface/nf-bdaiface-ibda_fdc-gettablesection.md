# IBDA_FDC::GetTableSection

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the latest table section.

## Parameters

### `Pid` [out]

Receives the packet identifier (PID) of the table.

### `MaxBufferSize` [in]

The size of the *SecBuffer* array, in bytes.

### `ActualSize` [out]

Receives the number of bytes that the method copies into the *SecBuffer* array.

### `SecBuffer` [out]

A byte array, allocated by the caller, that receives the table section.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_FDC](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_fdc)