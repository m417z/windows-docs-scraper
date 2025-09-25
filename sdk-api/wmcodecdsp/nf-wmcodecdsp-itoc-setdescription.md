# IToc::SetDescription

## Description

The **SetDescription** method associates a description with the table of contents.

## Parameters

### `pwszDescription` [in]

Pointer to a NULL-terminated, wide-character string that contains the description.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You can use this method to associate any description with the table of contents. TOC parser does not inspect or interpret the description.

## See also

[GetDescription](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itoc-getdescription)

[IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc)