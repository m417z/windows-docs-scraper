# WbemErrorEnum enumeration

## Description

The WbemErrorEnum constants define the errors that
may be returned by [Scripting API for WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/scripting-api-for-wmi)
calls.

The WMI scripting type library Wbemdisp.tlb defines these constants. Visual Basic applications can
access this library; script languages must use the value of the constant directly, unless they use the Windows
Script Host (WSH) XML file format. For more information, see
[Using the WMI Scripting Type Library](https://learn.microsoft.com/windows/desktop/WmiSdk/using-the-wmi-scripting-type-library).

Other languages may have different names for these values, see [WMI Error Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-error-constants) and [WBEMSTATUS](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbemstatus).

## Constants

### `wbemNoErr:0`

The call was successful.

### `wbemErrFailed:0x80041001`

The call failed.

### `wbemErrNotFound:0x80041002`

The object could not be found.

### `wbemErrAccessDenied:0x80041003`

The current user does not have permission to perform the action.

### `wbemErrProviderFailure:0x80041004`

The provider has failed at some time other than during initialization.

### `wbemErrTypeMismatch:0x80041005`

A type mismatch occurred.

### `wbemErrOutOfMemory:0x80041006`

There was not enough memory for the operation.

### `wbemErrInvalidContext:0x80041007`

The
[SWbemNamedValue](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemnamedvalue) object is not valid.

### `wbemErrInvalidParameter:0x80041008`

One of the parameters to the call is not correct.

### `wbemErrNotAvailable:0x80041009`

The resource, typically a remote server, is not currently available.

### `wbemErrCriticalError:0x8004100a`

An internal, critical, and unexpected error occurred. Report this error to Microsoft Technical
Support.

### `wbemErrInvalidStream:0x8004100b`

One or more network packets were corrupted during a remote session.

### `wbemErrNotSupported:0x8004100c`

The feature or operation is not supported.

### `wbemErrInvalidSuperclass:0x8004100d`

The parent class specified is not valid.

### `wbemErrInvalidNamespace:0x8004100e`

The namespace specified could not be found.

### `wbemErrInvalidObject:0x8004100f`

The specified instance is not valid.

### `wbemErrInvalidClass:0x80041010`

The specified class is not valid.

### `wbemErrProviderNotFound:0x80041011`

A provider referenced in the schema does not have a corresponding registration.

### `wbemErrInvalidProviderRegistration:0x80041012`

A provider referenced in the schema has an incorrect or incomplete registration. This error may be caused by
a missing [pragma namespace](https://learn.microsoft.com/windows/desktop/WmiSdk/pragma-namespace) command in the MOF file used to
register the provider, resulting in the provider being registered in the wrong WMI namespace. This error may also
be caused by a corrupt repository, which may be fixed by deleting it and recompiling the MOF files.

### `wbemErrProviderLoadFailure:0x80041013`

COM cannot locate a provider referenced in the schema. This error may be caused by any of the following:

The provider is using a WMI DLL that does not match the .lib fileused when the provider was built.

The provider's DLL or any of the DLLs on which it depends is corrupt.

The provider failed to export
[DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver).

An in-process provider was not registered using /regsvr32.

An out-of-process provider was not registered
using /regserver.

### `wbemErrInitializationFailure:0x80041014`

A component, such as a provider, failed to initialize for internal reasons.

### `wbemErrTransportFailure:0x80041015`

A networking error occurred, preventing normal operation.

### `wbemErrInvalidOperation:0x80041016`

The requested operation is not valid. This error usually applies to invalid attempts to delete classes or
properties.

### `wbemErrInvalidQuery:0x80041017`

The requested operation is not valid. This error usually applies to invalid attempts to delete classes or
properties.

### `wbemErrInvalidQueryType:0x80041018`

The requested query language is not supported.

### `wbemErrAlreadyExists:0x80041019`

In a put operation, the **wbemChangeFlagCreateOnly** flag was specified, but the
instance already exists.

### `wbemErrOverrideNotAllowed:0x8004101a`

It is not possible to perform the add operation on this qualifier because the owning object does not permit
overrides.

### `wbemErrPropagatedQualifier:0x8004101b`

The user attempted to delete a qualifier that was not owned. The qualifier was inherited from a parent
class.

### `wbemErrPropagatedProperty:0x8004101c`

The user attempted to delete a property that was not owned. The property was inherited from a parent
class.

### `wbemErrUnexpected:0x8004101d`

The client made an unexpected and illegal sequence of calls, such as calling
**EndEnumeration** before calling
**BeginEnumeration**.

### `wbemErrIllegalOperation:0x8004101e`

The user requested an illegal operation, such as spawning a class from an instance.

### `wbemErrCannotBeKey:0x8004101f`

There was an illegal attempt to specify a key qualifier on a property that cannot be a key. The keys are
specified in the class definition for an object, and cannot be altered on a per-instance basis.

### `wbemErrIncompleteClass:0x80041020`

The current object is not a valid class definition. Either it is incomplete, or it has not been registered
with WMI using [SWbemObject.Put_](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemobject-put-).

### `wbemErrInvalidSyntax:0x80041021`

The syntax of an input parameter is incorrect for the applicable data structure. For example, when a CIM
datetime structure does not have the correct format when passed to
[SWbemDateTime.SetFileTime](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemdatetime-setfiletime).

### `wbemErrNondecoratedObject:0x80041022`

Reserved for future use.

### `wbemErrReadOnly:0x80041023`

The property that you are attempting to modify is read-only.

### `wbemErrProviderNotCapable:0x80041024`

The provider cannot perform the requested operation. This would include a query that is too complex,
retrieving an instance, creating or updating a class, deleting a class, or enumerating a class.

### `wbemErrClassHasChildren:0x80041025`

An attempt was made to make a change that would invalidate a subclass.

### `wbemErrClassHasInstances:0x80041026`

An attempt has been made to delete or modify a class that has instances.

### `wbemErrQueryNotImplemented:0x80041027`

Reserved for future use.

### `wbemErrIllegalNull:0x80041028`

A value of Nothing was specified for a property that may not be Nothing, such as one that is marked by a
[Key](https://learn.microsoft.com/windows/desktop/WmiSdk/key-qualifier), **Indexed**,
or **Not_Null** qualifier.

### `wbemErrInvalidQualifierType:0x80041029`

The CIM type specified for a property is not valid.

### `wbemErrInvalidPropertyType:0x8004102a`

The CIM type specified for a property is not valid.

### `wbemErrValueOutOfRange:0x8004102b`

The request was made with an out-of-range value, or is incompatible with the type.

### `wbemErrCannotBeSingleton:0x8004102c`

An illegal attempt was made to make a class singleton, such as when the class is derived from a
non-singleton class.

### `wbemErrInvalidCimType:0x8004102d`

The CIM type specified is not valid.

### `wbemErrInvalidMethod:0x8004102e`

The requested method is not available.

### `wbemErrInvalidMethodParameters:0x8004102f`

The parameters provided for the method are not valid.

### `wbemErrSystemProperty:0x80041030`

There was an attempt to get qualifiers on a system property.

### `wbemErrInvalidProperty:0x80041031`

The property type is not recognized.

### `wbemErrCallCancelled:0x80041032`

An asynchronous process has been canceled internally or by the user. Note that due to the timing and nature
of the asynchronous operation the operation may not have been truly canceled.

### `wbemErrShuttingDown:0x80041033`

The user has requested an operation while WMI is in the process of shutting down.

### `wbemErrPropagatedMethod:0x80041034`

An attempt was made to reuse an existing method name from a parent class, and the signatures did not
match.

### `wbemErrUnsupportedParameter:0x80041035`

One or more parameter values, such as a query text, is too complex or unsupported. WMI is therefore
requested to retry the operation with simpler parameters.

### `wbemErrMissingParameter:0x80041036`

A parameter was missing from the method call.

### `wbemErrInvalidParameterId:0x80041037`

A method parameter has an [ID](https://learn.microsoft.com/windows/desktop/WmiSdk/standard-wmi-qualifiers)
qualifier that is not valid.

### `wbemErrNonConsecutiveParameterIds:0x80041038`

One or more of the method parameters have
[ID](https://learn.microsoft.com/windows/desktop/WmiSdk/standard-wmi-qualifiers) qualifiers that are out of
sequence.

### `wbemErrParameterIdOnRetval:0x80041039`

The return value for a method has an
[ID](https://learn.microsoft.com/windows/desktop/WmiSdk/standard-wmi-qualifiers) qualifier.

### `wbemErrInvalidObjectPath:0x8004103a`

The specified object path was not valid.

### `wbemErrOutOfDiskSpace:0x8004103b`

Disk is out of space or the 4 GB limit on WMI repository (CIM repository) size is reached.

### `wbemErrBufferTooSmall:0x8004103c`

The supplied buffer was too small to hold all the objects in the enumerator or to read a string
property.

### `wbemErrUnsupportedPutExtension:0x8004103d`

The provider does not support the requested put operation.

### `wbemErrUnknownObjectType:0x8004103e`

An object with an incorrect type or version was encountered during marshaling.

### `wbemErrUnknownPacketType:0x8004103f`

A packet with an incorrect type or version was encountered during marshaling.

### `wbemErrMarshalVersionMismatch:0x80041040`

The packet has an unsupported version.

### `wbemErrMarshalInvalidSignature:0x80041041`

The packet appears to be corrupted.

### `wbemErrInvalidQualifier:0x80041042`

An attempt has been made to mismatch qualifiers, such as putting [key] on an object instead of a
property.

### `wbemErrInvalidDuplicateParameter:0x80041043`

A duplicate parameter has been declared in a CIM method.

### `wbemErrTooMuchData:0x80041044`

Reserved for future use.

### `wbemErrServerTooBusy:0x80041045`

A call to [IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) has
failed. The provider may choose to refire the event.

### `wbemErrInvalidFlavor:0x80041046`

The specified flavor was not valid.

### `wbemErrCircularReference:0x80041047`

An attempt has been made to create a reference that is circular (for example, deriving a class from
itself).

### `wbemErrUnsupportedClassUpdate:0x80041048`

The specified class is not supported.

### `wbemErrCannotChangeKeyInheritance:0x80041049`

An attempt was made to change a key when instances or subclasses are already using the key.

### `wbemErrCannotChangeIndexInheritance:0x80041050`

An attempt was made to change an index when instances or subclasses are already using the index.

### `wbemErrTooManyProperties:0x80041051`

An attempt was made to create more properties than the current version of the class supports.

### `wbemErrUpdateTypeMismatch:0x80041052`

A property was redefined with a conflicting type in a derived class.

### `wbemErrUpdateOverrideNotAllowed:0x80041053`

An attempt was made in a derived class to override a non-overridable qualifier.

### `wbemErrUpdatePropagatedMethod:0x80041054`

A method was redeclared with a conflicting signature in a derived class.

### `wbemErrMethodNotImplemented:0x80041055`

An attempt was made to execute a method not marked with [implemented] in any relevant class.

### `wbemErrMethodDisabled:0x80041056`

An attempt was made to execute a method marked with [disabled].

### `wbemErrRefresherBusy:0x80041057`

The refresher is busy with another operation.

### `wbemErrUnparsableQuery:0x80041058`

The filtering query is syntactically not valid.

### `wbemErrNotEventClass:0x80041059`

The FROM clause of a filtering query references a class that is not an event class (not derived from
__Event).

### `wbemErrMissingGroupWithin:0x8004105a`

A GROUP BY clause was used without the corresponding GROUP WITHIN clause.

### `wbemErrMissingAggregationList:0x8004105b`

A GROUP BY clause was used. Aggregation on all properties is not supported.

### `wbemErrPropertyNotAnObject:0x8004105c`

Dot notation was used on a property that is not an embedded object.

### `wbemErrAggregatingByObject:0x8004105d`

A GROUP BY clause references a property that is an embedded object without using dot notation.

### `wbemErrUninterpretableProviderQuery:0x8004105f`

An event provider registration query
([__EventProviderRegistration](https://learn.microsoft.com/windows/desktop/WmiSdk/--eventproviderregistration)) did not
specify the classes for which events were provided.

### `wbemErrBackupRestoreWinmgmtRunning:0x80041060`

An request was made to back up or restore the repository while WMI was using it.

### `wbemErrQueueOverflow:0x80041061`

The asynchronous delivery queue overflowed due to the event consumer being too slow.

### `wbemErrPrivilegeNotHeld:0x80041062`

The operation failed because the client did not have the necessary security privilege.

### `wbemErrInvalidOperator:0x80041063`

The operator is not valid for this property type.

### `wbemErrLocalCredentials:0x80041064`

The user specified a username, password or authority for a local connection. The user must use a blank
username/password and rely on default security.

### `wbemErrCannotBeAbstract:0x80041065`

The class was made abstract when its parent class is not abstract.

### `wbemErrAmendedObject:0x80041066`

An amended object was put without the **wbemFlagUseAmendedQualifiers** flag being
specified.

### `wbemErrClientTooSlow:0x80041067`

The client was not retrieving objects quickly enough from an enumeration. This constant is returned when a
client creates an enumeration object but does not retrieve objects from the enumerator in a timely fashion,
causing the enumerator's object caches to get backed up.

### `wbemErrNullSecurityDescriptor:0x80041068`

A null security descriptor was used.

### `wbemErrTimeout:0x80041069`

The operation timed out.

### `wbemErrInvalidAssociation:0x8004106a`

The association being used is not valid.

### `wbemErrAmbiguousOperation:0x8004106b`

The operation was ambiguous.

### `wbemErrQuotaViolation:0x8004106c`

WMI is taking up too much memory. This could be caused either by low memory availability or excessive
memory consumption by WMI.

### `wbemErrTransactionConflict:0x8004106d`

The operation resulted in a transaction conflict.

### `wbemErrForcedRollback:0x8004106e`

The transaction forced a rollback.

### `wbemErrUnsupportedLocale:0x8004106f`

The locale used in the call is not supported.

### `wbemErrHandleOutOfDate:0x80041070`

The object handle is out of date.

### `wbemErrConnectionFailed:0x80041071`

Indicates that the connection to the SQL database failed.

### `wbemErrInvalidHandleRequest:0x80041072`

The handle request was not valid.

### `wbemErrPropertyNameTooWide:0x80041073`

The property name contains more than 255 characters.

### `wbemErrClassNameTooWide:0x80041074`

The class name contains more than 255 characters.

### `wbemErrMethodNameTooWide:0x80041075`

The method name contains more than 255 characters.

### `wbemErrQualifierNameTooWide:0x80041076`

The qualifier name contains more than 255 characters.

### `wbemErrRerunCommand:0x80041077`

Indicates that an SQL command should be rerun because there is a deadlock in SQL. This can be returned
only when data is being stored in an SQL database.

### `wbemErrDatabaseVerMismatch:0x80041078`

The database version does not match the version that the repository driver processes.

### `wbemErrVetoPut:0x80041079`

WMI cannot do the put operation because the provider does not allow it.

### `wbemErrVetoDelete:0x8004107a`

WMI cannot do the delete operation because the provider does not allow it.

### `wbemErrInvalidLocale:0x80041080`

The specified locale identifier was not valid for the operation.

### `wbemErrProviderSuspended:0x80041081`

The provider is suspended.

### `wbemErrSynchronizationRequired:0x80041082`

The object must be committed and retrieved again before the requested operation can succeed. This constant
is returned when an object must be committed and re-retrieved to see the property value.

### `wbemErrNoSchema:0x80041083`

The operation cannot be completed because no schema is available.

### `wbemErrProviderAlreadyRegistered:0x80041084`

The provider registration cannot be done because the provider is already registered.

### `wbemErrProviderNotRegistered:0x80041085`

The provider for the requested data is not registered.

### `wbemErrFatalTransportError:0x80041086`

A fatal transport error occurred and other transport will not be attempted.

### `wbemErrEncryptedConnectionRequired:0x80041087`

The client connection to WINMGMT must be encrypted for this operation. The
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) proxy security settings should be adjusted
and the operation retried.

### `wbemErrRegistrationTooBroad:0x80042001`

The provider registration overlaps with the system event domain.

### `wbemErrRegistrationTooPrecise:0x80042002`

A WITHIN clause was not used in this query.

### `wbemErrTimedout:0x80043001`

Automation-specific error.

### `wbemErrResetToDefault:0x80043002`

The user deleted an override default value for the current class. The default value for this property in
the parent class has been reactivated. An automation-specific error.

## See also

[Scripting API Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/scripting-api-constants)

[WBEMSTATUS](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbemstatus)

[WMI Error Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-error-constants)