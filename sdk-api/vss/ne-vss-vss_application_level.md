# VSS_APPLICATION_LEVEL enumeration

## Description

The **VSS_APPLICATION_LEVEL** enumeration indicates
the application level, the point in the course of the creation of a shadow copy that a writer is notified of a
freeze.

VSS first sends a [Freeze](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) event to writers
initialized with **VSS_APP_FRONT_END** (called front-end level applications), then to
writers initialized with **VSS_APP_BACK_END** (called back-end level applications), and
finally to writers initialized with **VSS_APP_SYSTEM** (called system-level
applications).

## Constants

### `VSS_APP_UNKNOWN:0`

The level at which this writer's freeze state will occur is not known. This indicates an application
error.

### `VSS_APP_SYSTEM:1`

This writer freeze state will occur at the system application level.

### `VSS_APP_BACK_END:2`

This writer freeze state will occur at the back-end application level.

### `VSS_APP_FRONT_END:3`

This writer freeze state will occur at the front-end application level.

### `VSS_APP_SYSTEM_RM:4`

### `VSS_APP_AUTO:-1`

This writer freeze state will be determined automatically. This enumeration value is reserved for future
use.

## Remarks

**VSS_APPLICATION_LEVEL** is provided to allow
application developers to control at what point a writer will receive a Freeze event. This may be important if one
writer uses or depends on another writer.

For instance, if an application *X* is storing data using application
*Y* as an intermediate layer (for example, if *Y* implements a
database used by *X*), we would describe *X* as a front-end
application, and *Y* as a back-end application.

In this example, when freezing applications that participate in a shadow copy, you would want
*X* (the front-end application) to suspend its writes to the database prior to freezing
*Y* (the back-end application), the database service itself.

The application level of a writer is set by
[CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize) and retrieved by
[CVssWriter::GetCurrentLevel](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getcurrentlevel).

## See also

[CVssWriter::GetCurrentLevel](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getcurrentlevel)

[CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize)