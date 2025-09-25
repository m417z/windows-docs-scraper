# WSL_DISTRIBUTION_FLAGS enumeration

## Description

The **WSL_DISTRIBUTION_FLAGS** enumeration specifies the behavior of a distribution in the Windows Subsystem for Linux (WSL).

## Constants

### `WSL_DISTRIBUTION_FLAGS_NONE:0x0`

 No flags are being supplied.

### `WSL_DISTRIBUTION_FLAGS_ENABLE_INTEROP:0x1`

 Allow the distribution to interoperate with Windows processes (for example, the user can invoke "cmd.exe" or "notepad.exe" from within a WSL session).

### `WSL_DISTRIBUTION_FLAGS_APPEND_NT_PATH:0x2`

 Add the Windows %PATH% environment variable values to WSL sessions.

### `WSL_DISTRIBUTION_FLAGS_ENABLE_DRIVE_MOUNTING:0x4`

 Automatically mount Windows drives inside of WSL sessions (for example, "C:\" will be available under "/mnt/c").