# ICEnroll3::get_ReuseHardwareKeyIfUnableToGenNew

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **ReuseHardwareKeyIfUnableToGenNew** property sets or retrieves a Boolean value that determines the action taken by the
certificate enrollment control object if an error is encountered when generating a new key.

This property was first defined in the [ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3) interface.

This property is read/write.

## Parameters

## Remarks

This property is a Boolean value. This property affects only [cryptographic service providers](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that return NTE_TOKEN_KEYSET_STORAGE_FULL. These CSPs are typically hardware-based; an example is a smart card. If this property is true and an error is encountered while generating a new key, the certificate enrollment control object will reuse the existing hardware key. If this property is false and an error is encountered while generating a new key, the certificate enrollment control object will not reuse the existing hardware key but will instead pass an error to the caller.

#### Examples

```cpp
// Code to set the reuse H/W key status.
// hr is HRESULT variable.
hr = pEnroll->put_ReuseHardwareKeyIfUnableToGenNew( FALSE );
if ( FAILED( hr ) )
    printf("Failed put_ReuseHardwareKeyIfUnableToGenNew [%x]\n", hr);

// Code to retrieve the reuse H/W key status.
BOOL bReuse;

hr = pEnroll->get_ReuseHardwareKeyIfUnableToGenNew( &bReuse );
if ( FAILED( hr ) )
    printf("Failed get_ReuseHardwareKeyIfUnableToGenNew [%x]\n", hr);
else
    printf("Hardware key %s be reused if unable"
        " to generate a new key.\n", bReuse ? "will" : "will not");
```

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)