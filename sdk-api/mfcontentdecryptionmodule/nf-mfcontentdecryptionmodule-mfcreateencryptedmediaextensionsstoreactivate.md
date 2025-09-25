## Description

This function creates an object that implements [IMFActivate](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfactivate). This object’s implementation of ActivateObject is based on the specified IMFPMPHostApp and class ID.

## Parameters

### `pmpHost`

An [IMFPMPHostApp](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfpmphostapp) with the necessary information to create the **IMFActivate** for this app package.

### `objectStream`

An [IStream](https://learn.microsoft.com/windows/win32/api/objidl/nn-objidl-istream) representing the object stream that will be loaded via IMFActivate::Load.

### `classId`

An **LPCWSTR** representing the target object's activatable class id.

### `activate`

Receives a reference to the to an **IMFActivate**.

## Return value

Returns S_OK on success.

## Remarks

The **IMFActivate** can be created in a protected process and activated in an app process.

## See also