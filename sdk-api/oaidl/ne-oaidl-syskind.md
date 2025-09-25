# SYSKIND enumeration

## Description

Identifies the target operating system platform.

## Constants

### `SYS_WIN16:0`

The target operating system for the type library is 16-bit Windows. By default, data members are packed.

### `SYS_WIN32`

The target operating system for the type library is 32-bit Windows. By default, data members are naturally aligned (for example, 2-byte integers are aligned on even-byte boundaries; 4-byte integers are aligned on quad-word boundaries, and so on).

### `SYS_MAC`

The target operating system for the type library is Apple Macintosh. By default, all data members are aligned on even-byte boundaries.

### `SYS_WIN64`

The target operating system for the type library is 64-bit Windows.