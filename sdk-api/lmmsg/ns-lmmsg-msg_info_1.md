# MSG_INFO_1 structure

## Description

The
**MSG_INFO_1** structure specifies a message alias. This structure exists only for compatibility. Message forwarding is not supported.

## Members

### `msgi1_name`

Pointer to a Unicode string that specifies the alias to which the message is to be sent. The constant LEN specifies the maximum number of characters in the string.

### `msgi1_forward_flag`

This member must be zero.

### `msgi1_forward`

This member must be **NULL**.

## See also

[Message Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/message-functions)

[NetMessageNameEnum](https://learn.microsoft.com/windows/desktop/api/lmmsg/nf-lmmsg-netmessagenameenum)

[NetMessageNameGetInfo](https://learn.microsoft.com/windows/desktop/api/lmmsg/nf-lmmsg-netmessagenamegetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)