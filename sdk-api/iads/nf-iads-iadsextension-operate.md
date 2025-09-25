# IADsExtension::Operate

## Description

The **IADsExtension::Operate** method is invoked by the aggregator to perform the extended functionality. The method interprets the control code and input parameters according to the specifications of the provider. For more information, see the provider documentation.

## Parameters

### `dwCode` [in]

A value of the ADSI extension control code. ADSI defines the following code value.

#### ADS_EXT_INITCREDENTIALS

Verifies user credentials in the extension object.

### `varData1` [in]

Provider-supplied data the extension object will operate on. The value depends upon the control code value and is presently undefined.

### `varData2` [in]

Provider-supplied data the extension object will operate on. The value depends upon the control code value and is presently undefined.

### `varData3` [in]

Provider-supplied data the extension object will operate on. The value depends upon the control code value and is presently undefined.

## Return value

This method supports the standard return values, as well as the following:

For more information about other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The aggregator will ignore the **E_FAIL** and **E_NOTIMPL** return values.

#### Examples

The following C/C++ code example shows a generic implementation.

```cpp
STDMETHOD(Operate)(ULONG dwCode, VARIANT varData1, VARIANT varData2, VARIANT varData3)
{
   HRESULT hr = S_OK;
   switch (dwCode)
   {
      case ADS_EXT_INITCREDENTIALS:
      // Prompt for a credential.
      // MessageBox(NULL, "INITCRED", "ADsExt", MB_OK);

      break;
      default:
          hr = E_FAIL;
      break;
    }
    return hr;
}
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsExtension](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsextension)