# IStreamBufferConfigure::GetDirectory

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetDirectory** method retrieves the directory where backing files are saved.

## Parameters

### `ppszDirectoryName` [out]

Pointer to a variable that receives the fully qualified directory name.

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The caller must free the returned string by calling **CoTaskMemFree**.

## See also

[IStreamBufferConfigure Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferconfigure)