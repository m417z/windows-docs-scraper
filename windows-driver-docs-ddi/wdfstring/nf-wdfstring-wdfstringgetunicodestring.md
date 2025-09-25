# WdfStringGetUnicodeString function

## Description

[Applies to KMDF and UMDF]

The **WdfStringGetUnicodeString** method retrieves the Unicode string that is assigned to a specified framework string object.

## Parameters

### `String` [in]

A handle to a framework string object.

### `UnicodeString` [out]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that receives a pointer to the Unicode string that is currently assigned to the string object that *String* specifies.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

After **WdfStringGetUnicodeString** returns, the UNICODE_STRING structure that *UnicodeString* points to contains a pointer to the specified string object's Unicode string, along with the string's length. The Unicode string is allocated in paged pool.

 The framework does not make a copy of the string for the driver.

For more information about framework string objects, see [Using String Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-string-objects).

#### Examples

The following code example obtains the Unicode string that is assigned to a specified framework string object.

```cpp
UNICODE_STRING StringName;

WdfStringGetUnicodeString(
                          stringHandle,
                          &StringName
                          );
```

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdfStringCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringcreate)