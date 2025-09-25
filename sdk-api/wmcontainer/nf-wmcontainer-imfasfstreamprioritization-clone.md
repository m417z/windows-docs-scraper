# IMFASFStreamPrioritization::Clone

## Description

**Note** This interface is not implemented in this version of Media Foundation.

Creates a copy of the ASF stream prioritization object.

## Parameters

### `ppIStreamPrioritization` [out]

Receives a pointer to the [IMFASFStreamPrioritization](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamprioritization) interface of the new object. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The new object is completely independent of the original.

## See also

[IMFASFStreamPrioritization](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamprioritization)