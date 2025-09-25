# AssocCreateForClasses function

## Description

Retrieves an object that implements an [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) interface.

## Parameters

### `rgClasses` [in]

Type: **const [ASSOCIATIONELEMENT](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-associationelement)***

A pointer to an array of [ASSOCIATIONELEMENT](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-associationelement) structures.

### `cClasses` [in]

Type: **ULONG**

The number of elements in the array pointed to by *rgClasses*.

### `riid` [in]

Type: **REFIID**

Reference to the desired IID, normally IID_IQueryAssociations.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is normally [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For systems earlier than Windows Vista, use the [AssocCreate](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-assoccreate) function.