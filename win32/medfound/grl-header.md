# GRL\_HEADER structure

Contains the global revocation list (GRL) header.

## Members

**wszIdentifier**

The GRL identifier. The value is always L"MSGRL".

**wFormatMajor**

The major version number. Currently the value must be 1.

**wFormatMinor**

The minor version number. Currently the value must be zero.

**CreationTime**

A **FILETIME** value that specifies when the file was created.

**dwSequenceNumber**

The GRL version number. Currently the value must be at least 3

**dwForceRebootVersion**

Reserved.

**dwForceProcessRestartVersion**

Reserved.

**cbRevocationSectionOffset**

The offset, in bytes, from the start of the GRL to the Core section.

**cRevokedKernelBinaries**

The number of revoked kernel binaries listed in the GRL.

**cRevokedUserBinaries**

The number of revoked user-mode binaries listed in the GRL.

**cRevokedCertificates**

The number of revoked certificates listed in the GRL.

**cTrustedRoots**

The number of trusted roots listed in the GRL.

**cbExtensibleSectionOffset**

The offset, in bytes, from the start of the GRL to the Extensible section.

**cExtensibleEntries**

The number of entries in the Extensible section.

**cbRenewalSectionOffset**

The offset, in bytes, from the start of the GRL to the Renewals section.

**cRevokedKernelBinaryRenewals**

The number of kernel binary renewals listed in the GRL.

**cRevokedUserBinaryRenewals**

The number of user-mode binary renewals listed in the GRL.

**cRevokedCertificateRenewals**

The number of certificate renewals listed in the GRL.

**cbSignatureCoreOffset**

The offset, in bytes, from the start of the GRL to the Core section signature.

**cbSignatureExtOffset**

The offset, in bytes, from the start of the GRL to the Extensible section signature.

## Remarks

All integers in the GRL have little-endian byte ordering. All structures are aligned to 1-byte boundaries.

This structure is not declared in an SDK header. To use this structure, add the declaration shown here to your source code.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |

## See also

[OPM Certificate Revocation](https://learn.microsoft.com/windows/win32/medfound/opm-certificate-revocation)

[OPM Structures](https://learn.microsoft.com/windows/win32/medfound/opm-structures)

