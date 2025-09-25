# BCryptFreeBuffer function

## Description

The **BCryptFreeBuffer** function is used to free memory that was allocated by one of the CNG functions.

## Parameters

### `pvBuffer` [in]

A pointer to the memory buffer to be freed.

## Remarks

**BCryptFreeBuffer** must be called in the same processor mode as the BCrypt API function that allocated the buffer. In addition, if the buffer was allocated at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly), it must be freed at that *IRQL*. If the buffer was allocated at **DISPATCH_LEVEL** *IRQL*, it can be freed at either **DISPATCH_LEVEL** *IRQL* or **PASSIVE_LEVEL** *IRQL*.

To call this function in kernel mode, use Cng.lib, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use Ksecdd.lib.

## See also

[BCryptEnumContexts](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptenumcontexts)

[BCryptEnumRegisteredProviders](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptenumregisteredproviders)

[BCryptQueryProviderRegistration](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptqueryproviderregistration)