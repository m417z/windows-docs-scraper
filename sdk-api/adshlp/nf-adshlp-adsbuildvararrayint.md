# ADsBuildVarArrayInt function

## Description

The **ADsBuildVarArrayInt** function builds a variant array of integers from an array of **DWORD** values.

## Parameters

### `lpdwObjectTypes` [in]

Type: **LPDWORD**

Array of **DWORD** values.

### `dwObjectTypes` [in]

Type: **DWORD**

Number of **DWORD** entries in the given array.

### `pVar` [out]

Type: **VARIANT***

Pointer to the resulting variant array of integers.

## Return value

Type: **HRESULT**

This method supports standard return values.

For more information about other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

Use the **ADsBuildVarArrayInt** function to convert the integer array into a variant array of the integers. The following code example shows how to do this.

```cpp
DWORD dwArray[]={0,1,2,3,4};
long nLength = sizeof(dwArray)/sizeof(DWORD);
VARIANT varArray[nLength];
HRESULT hr = ADsBuildVarArrayInt(dwArray, nLength, varArray);
if (hr = E_FAIL) exit(1);

// Resume work with the data in varArray.
. . .
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[ADsBuildVarArrayStr](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsbuildvararraystr)