# RegOpenKeyTransactedW function

## Description

Opens the specified registry key and associates it with a transaction. Note that key names are not case sensitive.

## Parameters

### `hKey` [in]

A handle to an open registry key. This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa), [RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda), [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa), or
**RegOpenKeyTransacted** function. It can also be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**
**HKEY_CURRENT_USER**
**HKEY_LOCAL_MACHINE**
**HKEY_USERS**

### `lpSubKey` [in, optional]

The name of the registry subkey to be opened.

Key names are not case sensitive.

If the *lpSubKey* parameter is **NULL** or a pointer to an empty string,
and if *hKey* is a predefined key,
then the system refreshes the predefined key,
and *phkResult* receives the same *hKey* handle passed into the function.
Otherwise, *phkResult* receives a new handle to the opened key.

For more information, see
[Registry Element Size Limits](https://learn.microsoft.com/windows/desktop/SysInfo/registry-element-size-limits).

### `ulOptions` [in]

This parameter is reserved and must be zero.

### `samDesired` [in]

A mask that specifies the desired access rights to the key. The function fails if the security descriptor of the key does not permit the requested access for the calling process. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

### `phkResult` [out]

A pointer to a variable that receives a handle to the opened key. If the key is not one of the predefined registry keys, call the
[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey) function after you have finished using the handle.

### `hTransaction` [in]

A handle to an active transaction. This handle is returned by the [CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

### `pExtendedParemeter`

This parameter is reserved and must be **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

When a key is opened using this function, subsequent operations on the key are transacted. If a non-transacted operation is performed on the key before the transaction is committed, the transaction is rolled back. After a transaction is committed or rolled back, you must re-open the key using the [RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda) or **RegOpenKeyTransacted** function with an active transaction handle to make additional operations transacted. For more information about transactions, see [Kernel Transaction Manager](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-portal).

Note that subsequent operations on subkeys of this key are not automatically transacted. Therefore, the [RegDeleteKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeyexa) function does not perform a transacted delete operation. Instead, use the [RegDeleteKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeytransacteda) function to perform a transacted delete operation.

Unlike the
[RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda) function, the
**RegOpenKeyTransacted** function does not create the specified key if the key does not exist in the registry.

If your service or application impersonates different users, do not use this function with **HKEY_CURRENT_USER**. Instead, call the [RegOpenCurrentUser](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopencurrentuser) function.

If the key returned in *phkResult* is a predefined registry key, it is not included in the provided transaction.

A single registry key can be opened only 65,534 times. When attempting the 65,535th open operation, this function fails with ERROR_NO_SYSTEM_RESOURCES.

> [!NOTE]
> The winreg.h header defines RegOpenKeyTransacted as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey)

[RegCreateKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeytransacteda)

[RegDeleteKeyTransacted](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)