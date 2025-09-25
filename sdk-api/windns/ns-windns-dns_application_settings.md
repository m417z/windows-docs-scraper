## Description

Represents per-application DNS settings.

## Members

### `Version`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Must be set to **DNS_APP_SETTINGS_VERSION1**.

### `Flags`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A bitset containing the following options.

* **DNS_APP_SETTINGS_EXCLUSIVE_SERVERS** (0x1). Use the custom DNS servers exclusively, and don't try the system-configured ones.

## Remarks

## See also