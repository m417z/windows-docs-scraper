# MPTHREAT\_INFOEX\_BEHAVIOR structure

Contains behavior modification-specific information.

## Members

**SignatureID**

Type: **ULARGE\_INTEGER**

Behavior modification signature ID given by the engine at the time of detection.

**EngineVersion**

Type: **ULONGLONG**

Engine module version.

**ASDeltaSignatureVersion**

Type: **ULONGLONG**

Antispyware signature version.

**AVDeltaSignatureVersion**

Type: **ULONGLONG**

Antivirus signature version

**HashType**

Type: **[**MP\_HASH\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mp-hash-type)**

Hash type used. See [**MP\_HASH\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mp-hash-type).

**FidelityValue**

Type: **DWORD**

Fidelity value.

**HashValue**

Type: **MP\_MIDL\_STRING LPWSTR**

The hash of the file.

**TargetFileName**

Type: **MP\_MIDL\_STRING LPWSTR**

The path and name of the targeted file.

**TargetFileHash**

Type: **MP\_MIDL\_STRING LPWSTR**

The hash of the targeted file.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

## See also

[**MP\_HASH\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mp-hash-type)

