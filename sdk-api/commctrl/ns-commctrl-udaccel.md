# UDACCEL structure

## Description

Contains acceleration information for an up-down control.

## Members

### `nSec`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Amount of elapsed time, in seconds, before the position change increment specified by
**nInc** is used.

### `nInc`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Position change increment to use after the time specified by
**nSec** elapses.