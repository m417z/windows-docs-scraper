## Description

The **AcxStreamGetNotificationId** function retrieves the Plug and Play notification ID for the specified audio stream.

## Parameters

### `Stream` [in]

The ACX stream object for which to retrieve the Plug and Play notification ID.

## Return value

Returns a GUID containing the Plug and Play notification ID for the object specified by the *Stream* parameter.

## Remarks

### Example

Example usage is shown below.

```cpp
...
    _In_ ACXSTREAM Stream,
...

    GUID        notificationId;
...

    notificationId = AcxStreamGetNotificationId(Stream);
```

### ACX requirements

**Minimum ACX version:** 1.1

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)