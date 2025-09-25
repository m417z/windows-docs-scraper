# NtSetInformationTransactionManager function

## Description

Do not call this routine from kernel-mode code.

## Parameters

### `TmHandle` [in, optional]

### `TransactionManagerInformationClass` [in]

### `TransactionManagerInformation` [in]

### `TransactionManagerInformationLength` [in]

## Return value

See the **Zw*Xxx*** equivalent.

Do not call this routine from kernel-mode code; instead, call the **Zw*Xxx*** equivalent. User-mode code can call this routine or the **Zw*Xxx*** equivalent. For further comments, if any, see the ZwXxx equivalent

The driver must check the return value of the function.

## See also

See the **Zw*Xxx*** equivalent.