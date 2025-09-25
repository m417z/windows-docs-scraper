# UiaGetRuntimeId function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Retrieves the runtime identifier of a UI Automation node.

## Parameters

### `hnode` [in]

Type: **HUIANODE**

The node for which the identifier is being requested.

### `pruntimeId` [out]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)****

The address of a variable that receives a pointer to a [SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray) that contains the runtime identifier of the type VT_I4. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

The runtime identifier should be treated as an opaque value and used only for comparison.