# BIND_FLAGS enumeration

## Description

Controls aspects of moniker binding operations.

## Constants

### `BIND_MAYBOTHERUSER:1`

If this flag is specified, the moniker implementation can interact with the end user. Otherwise, the moniker implementation should not interact with the user in any way, such as by asking for a password for a network volume that needs mounting. If prohibited from interacting with the user when it otherwise would, a moniker implementation can use a different algorithm that does not require user interaction, or it can fail with the error MK_E_MUSTBOTHERUSER.

### `BIND_JUSTTESTEXISTENCE:2`

If this flag is specified, the caller is not interested in having the operation carried out, but only in learning whether the operation could have been carried out had this flag not been specified. For example, this flag lets the caller indicate only an interest in finding out whether an object actually exists by using this flag in a [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) call. Moniker implementations can, however, ignore this possible optimization and carry out the operation in full. Callers must be able to deal with both cases.

## See also

[BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts)

[BIND_OPTS2](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-bind_opts2-r1)

[BIND_OPTS3](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-bind_opts3-r1)