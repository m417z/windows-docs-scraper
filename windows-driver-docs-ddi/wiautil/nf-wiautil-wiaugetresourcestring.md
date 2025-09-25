# wiauGetResourceString function

## Description

The **wiauGetResourceString** function gets a resource string, storing it as a **BSTR**.

## Parameters

### `hInst`

Specifies the handle of the module instance.

### `lResourceID`

Specifies the resource ID of the target BSTR value.

### `pbstrStr` [out]

Points to the memory location that receives the retrieved string. The caller of this function must free this string by calling **SysFreeString** (described in the Microsoft Windows SDK documentation).

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error.