# _FILE_MAILSLOT_QUERY_INFORMATION structure

## Description

The **FILE_MAILSLOT_QUERY_INFORMATION** structure contains information about a mailslot.

## Members

### `MaximumMessageSize`

The maximum size, in bytes, of a single message that can be written to the mailslot, or 0 for a message of any size.

### `MailslotQuota`

The size, in bytes, of the in-memory pool that is reserved for writes to this mailslot.

### `NextMessageSize`

The next message size, in bytes.

### `MessagesAvailable`

The total number of messages waiting to be read from the mailslot.

### `ReadTimeout`

The time, in milliseconds, that a read operation can wait for a message to be written to the mailslot before a time-out occurs. A value of –1 requests that the read wait forever for a message, without timing out. A value of 0 requests that the read not wait and return immediately whether a pending message is available to be read or not.

## Remarks

For more information, see [Mailslots](https://learn.microsoft.com/windows/desktop/ipc/mailslots).