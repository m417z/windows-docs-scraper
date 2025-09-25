# ADS_DEREFENUM enumeration

## Description

The **ADS_DEREFENUM** enumeration specifies the process through which aliases are dereferenced.

## Constants

### `ADS_DEREF_NEVER:0`

Does not dereference aliases when searching or locating the base object of the search.

### `ADS_DEREF_SEARCHING:1`

Dereferences aliases when searching subordinates of the base object, but not when locating the base itself.

### `ADS_DEREF_FINDING:2`

Dereferences aliases when locating the base object of the search, but not when searching its subordinates.

### `ADS_DEREF_ALWAYS:3`

Dereferences aliases when both searching subordinates and locating the base object of the search.

## Remarks

The [IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch) interface uses these constants to set the alias dereferencing behavior. If no option is specified, the server defaults to **ADS_DEREF_NEVER**.

**Note** Because VBScript cannot read data from a type library, VBScript applications do not recognize the symbolic constants as defined above. Use the numerical constants, instead, to set the appropriate flags in your VBScript applications. To use the symbolic constants, as a good programming practice, explicitly declare constants, as done here.

#### Examples

The following code example shows how to set the search preference for alias dereferencing. m_pSearch refers to a pointer to an object implementing the [IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch) interface.

```cpp
ADS_SEARCHPREF_INFO prefInfo[1];
HRESULT hr;

prefInfo[0].dwSearchPref   = ADS_SEARCHPREF_DEREF_ALIASES;
prefInfo[0].vValue.dwType  = ADSTYPE_INTEGER;
prefInfo[0].vValue.Integer = ADS_DEREF_ALWAYS;
hr = m_pSearch->SetSearchPreference(prefInfo, 1);
```

## See also

[ADSI
Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch)