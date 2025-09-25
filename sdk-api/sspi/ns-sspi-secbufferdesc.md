# SecBufferDesc structure

## Description

The **SecBufferDesc** structure describes an array of [SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structures to pass from a transport application to a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Members

### `ulVersion`

Specifies the version number of this structure. This member must be SECBUFFER_VERSION.

### `cBuffers`

Indicates the number of [SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structures in the **pBuffers** array.

### `pBuffers`

Pointer to an array of [SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer) structures.

### `pBuffers.size_is`

### `pBuffers.size_is.cBuffers`

## See also

[SecBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbuffer)