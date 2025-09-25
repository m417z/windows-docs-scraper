# PEERDIST_RETRIEVAL_OPTIONS structure

## Description

The **PEER_RETRIEVAL_OPTIONS** structure contains version of the content information to retrieve.

## Members

### `cbSize`

Specifies the size of the input structure.

### `dwContentInfoMinVersion`

Specifies the minimum version of the content information to retrieve. Must be set to one of the following values:

#### PEERDIST_RETRIEVAL_OPTIONS_CONTENTINFO_VERSION

#### PEERDIST_RETRIEVAL_OPTIONS_CONTENTINFO_VERSION_1

#### PEERDIST_RETRIEVAL_OPTIONS_CONTENTINFO_VERSION_2

### `dwContentInfoMaxVersion`

Specifies the maximum version of the content information to retrieve. Must be set to one of the following values:

#### PEERDIST_RETRIEVAL_OPTIONS_CONTENTINFO_VERSION

#### PEERDIST_RETRIEVAL_OPTIONS_CONTENTINFO_VERSION_1

#### PEERDIST_RETRIEVAL_OPTIONS_CONTENTINFO_VERSION_2

### `dwReserved`

Reserved. The **dwReserved** member should be set to 0.

## See also

[PeerDistServerOpenContentInformationEx](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformationex)