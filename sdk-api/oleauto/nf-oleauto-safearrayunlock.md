# SafeArrayUnlock function

## Description

Decrements the lock count of an array so it can be freed or resized.

## Parameters

### `psa` [in]

An array descriptor created by [SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate).

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* is not valid. |
| **E_UNEXPECTED** | The array could not be unlocked. |

## Remarks

This function is called after access to the data in an array is finished.

#### Thread Safety

All public static members of the [SAFEARRAY data type](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) are thread safe. Instance members are not guaranteed to be thread safe.

For example, consider an application that uses the [SafeArrayLock](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraylock) and SafeArrayUnlock functions. If these functions are called concurrently from different threads on the same [SAFEARRAY data type](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) instance, an inconsistent lock count may be created. This will eventually cause the SafeArrayUnlock function to return E_UNEXPECTED. You can prevent this by providing your own synchronization code.