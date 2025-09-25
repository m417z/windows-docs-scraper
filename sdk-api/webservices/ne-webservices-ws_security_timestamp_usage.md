# WS_SECURITY_TIMESTAMP_USAGE enumeration

## Description

With message security and mixed-mode security, this defines when a
timestamp element should be generated and demanded in the WS-Security
header.

## Constants

### `WS_SECURITY_TIMESTAMP_USAGE_ALWAYS:1`

Always generate a timestamp in each outgoing message and demand a
timestamp be present in each incoming message, whether those messages
are requests or replies.

### `WS_SECURITY_TIMESTAMP_USAGE_NEVER:2`

Do not use timestamps in requests or replies. It is an error to
specify this value when a mixed-mode message signature is required in
the WS-Security header.

### `WS_SECURITY_TIMESTAMP_USAGE_REQUESTS_ONLY:3`

Generate and demand timestamps in client to server request messages,
but not in server to client reply messages. This value may be used in
mixed-mode security.