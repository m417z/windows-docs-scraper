# GPMBackupType enumeration

## Description

**GPMBackupType** defines the type of backup created.

**GPMBackupType** determines whether the backup is for a Group Policy object or a Starter Group Policy object.

```cpp
typedef enum {
    typeGPO = 0,
    typeStarterGPO
} GPMBackupType;
```

## Constants

### `typeGPO:0`

Backup of a Group Policy object.

### `typeStarterGPO`

Backup of a Starter Group Policy object.