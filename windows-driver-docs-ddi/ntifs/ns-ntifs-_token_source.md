# TOKEN_SOURCE structure

## Description

The **TOKEN_SOURCE** structure identifies the source of an access token.

## Members

### `SourceName`

Specifies an 8-byte character string used to identify the source of an access token. This is used to distinguish between such sources as Session Manager, LAN Manager, and RPC Server. A string, rather than a constant, is used to identify the source so users and developers can make extensions to the system, such as by adding other networks, that act as the source of access tokens. Note that TOKEN_SOURCE_LENGTH currently equals 8.

### `SourceIdentifier`

Specifies a locally unique identifier (LUID) provided by the source component named by the **SourceName** member. This value aids the source component in relating context blocks, such as session-control structures, to the token. This value is typically, but not necessarily, an LUID.

## See also

[**LUID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**TOKEN_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-_token_information_class)

[**ZwQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryinformationtoken)

[**ZwSetInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetinformationtoken)