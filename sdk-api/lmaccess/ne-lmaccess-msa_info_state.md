# MSA_INFO_STATE enumeration

## Description

Indicates the state of a managed service account. A managed service account can be either a group managed service account (gMSA) or a standalone managed service account (sMSA). A sMSA is limited to being deployed to a single computer.

## Constants

### `MsaInfoNotExist:1`

The account does not exist.

### `MsaInfoNotService`

The account exists, but it is not a group managed service account (gMSA) or a Windows Server 2008 R2 or Windows 7 managed service account.

**Windows Server 2008 R2 and Windows 7:**  The account is not a managed service account.

### `MsaInfoCannotInstall`

If the managed service account is a gMSA, the credentials cannot be fetched from the active directory or the Kerberos encryption types did not match.

**Windows Server 2008 R2 and Windows 7:**  The managed service account cannot be installed.

### `MsaInfoCanInstall`

The sMSA can be installed. This constant will never be returned for a gMSA.

**Windows Server 2008 R2 and Windows 7:**  The managed service account can be installed.

### `MsaInfoInstalled`

The gMSA managed service account is installed.

**Windows Server 2008 R2 and Windows 7:**  The managed service account is installed.

## Remarks

Service accounts can be group managed and are called group managed service accounts (gMSA). Standalone managed service accounts (sMSA) are limited to being deployed to a single computer.

**Windows Server 2008 R2 and Windows 7:**  The managed service account (MSA) is limited to being deployed to a single computer.

## See also

[MSA_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-msa_info_0)