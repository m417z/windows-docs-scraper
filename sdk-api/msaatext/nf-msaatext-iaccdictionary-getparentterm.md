# IAccDictionary::GetParentTerm

## Description

Clients call the **IAccDictionary::GetParentTerm** method to navigate through the object hierarchy tree. This method returns the parent object of a specified property.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `Term` [in]

Type: **REFGUID**

A GUID for a property.

### `pParentTerm` [out]

Type: **GUID***

The parent of the property specified in the *Term* parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

## Remarks

If there is not a parent term for *Term*, then *pParentTerm* will point to GUID_NULL.