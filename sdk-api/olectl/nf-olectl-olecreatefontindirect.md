# OleCreateFontIndirect function

## Description

Creates and initializes a standard font object using an initial description of the font's properties in a [FONTDESC](https://learn.microsoft.com/windows/desktop/api/olectl/ns-olectl-fontdesc) structure. The function returns an interface pointer to the new font object specified by caller in the riid parameter. A [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) call is part of this call. The caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) through the interface pointer returned.

## Parameters

### `lpFontDesc` [in]

Address of a caller-allocated, [FONTDESC](https://learn.microsoft.com/windows/desktop/api/olectl/ns-olectl-fontdesc) structure containing the initial state of the font. This value must not be **NULL**.

### `riid` [in]

Reference to the identifier of the interface describing the type of interface pointer to return in *lplpvObj*.

### `lplpvObj` [out]

 Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, this parameter contains the requested interface pointer on the newly created font object. If successful, the caller is responsible to call Release through this interface pointer when the new object is no longer needed. If unsuccessful, the value of is set to **NULL**.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The provided interface identifier is invalid. |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_OUTOFMEMORY** | Insufficient memory for the operation. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_POINTER** | The address in *pFontDesc* or *ppvObj* is not valid. Note that if *pFontDesc* is set to **NULL**, the function returns NO_ERROR. |

## See also

[FONTDESC](https://learn.microsoft.com/windows/desktop/api/olectl/ns-olectl-fontdesc)