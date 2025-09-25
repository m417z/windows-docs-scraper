# PROCESS_PROTECTION_LEVEL_INFORMATION structure

## Description

Specifies whether Protected Process Light (PPL) is enabled.

## Members

### `ProtectionLevel`

The one of the following values.

| Value | Meaning |
| --- | --- |
| **PROTECTION_LEVEL_WINTCB_LIGHT** | For internal use only. |
| **PROTECTION_LEVEL_WINDOWS** | For internal use only. |
| **PROTECTION_LEVEL_WINDOWS_LIGHT** | For internal use only. |
| **PROTECTION_LEVEL_ANTIMALWARE_LIGHT** | For internal use only. |
| **PROTECTION_LEVEL_LSA_LIGHT** | For internal use only. |
| **PROTECTION_LEVEL_WINTCB** | Not implemented. |
| **PROTECTION_LEVEL_CODEGEN_LIGHT** | Not implemented. |
| **PROTECTION_LEVEL_AUTHENTICODE** | Not implemented. |
| **PROTECTION_LEVEL_PPL_APP** | The process is a third party app that is using process protection. |
| **PROTECTION_LEVEL_NONE** | The process is not protected. |