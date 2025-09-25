# _FILE_MAILSLOT_SET_INFORMATION structure

## Description

The **FILE_MAILSLOT_SET_INFORMATION** structure is used to set a value on a mailslot.

## Members

### `ReadTimeout`

The time, in milliseconds, that a read operation can wait for a message to be written to the mailslot before a time-out occurs. A value of –1 requests that the read wait forever for a message without timing out. A value of 0 requests that the read not wait and return immediately whether a pending message is available to be read or not.

## Remarks

For more information, see [Mailslots](https://learn.microsoft.com/windows/desktop/ipc/mailslots).