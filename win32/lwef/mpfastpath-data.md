# MPFASTPATH\_DATA structure

FastPath update notification.

## Members

**SignatureType**

Type: **[**MP\_SIGNATURE\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mp-signature-type)**

Signature type.

**FastPathSignatureType**

Type: **[**MP\_FASTPATH\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mp-fastpath-type)**

FastPath signature type.

**FastPathSignatureVersion**

Type: **MP\_MIDL\_STRING LPWSTR**

FastPath signature version (optional).

**CompilationTimestamp**

Type: **ULARGE\_INTEGER**

Compilation timestamp (UTC).

**PersistenceType**

Type: **[**MP\_PERSISTENCE\_LIMIT\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mp-persistence-limit-type)**

Persistence type (optional).

**PersistenceValue**

Type: **MP\_MIDL\_STRING LPWSTR**

Persistence value (optional).

**PersistencePath**

Type: **MP\_MIDL\_STRING LPWSTR**

Persistence path (optional).

**Reason**

Type: **[**MP\_REMOVAL\_REASON**](https://learn.microsoft.com/windows/win32/lwef/mp-removal-reason)**

Reason for signature removal.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

## See also

[**MP\_FASTPATH\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mp-fastpath-type)

[**MP\_PERSISTENCE\_LIMIT\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mp-persistence-limit-type)

[**MP\_SIGNATURE\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mp-signature-type)

