# ATTACHMENT_PROMPT enumeration

## Description

Provides a set of flags to be used with [IAttachmentExecute::Prompt](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-prompt) to indicate the type of prompt UI to display.

## Constants

### `ATTACHMENT_PROMPT_NONE:0`

Do not use.

### `ATTACHMENT_PROMPT_SAVE:0x1`

Displays a prompt asking whether the user would like to save the attachment.

### `ATTACHMENT_PROMPT_EXEC:0x2`

Displays a prompt asking whether the user would like to execute the attachment.

### `ATTACHMENT_PROMPT_EXEC_OR_SAVE:0x3`

Displays a prompt giving the user a choice of executing or saving the attachment.