# NAME_CACHE_CONTEXT structure

## Description

Represents a name cache. This structure does not contain any fields that are useful to a client, but it must be passed back into all of the name cache APIs.

## Members

### `m_dwSignature`

The signature to this structure to ensure whether this name cache context is valid.

**Note** Users should never change this for any reason.