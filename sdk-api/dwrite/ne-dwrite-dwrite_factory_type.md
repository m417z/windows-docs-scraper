# DWRITE_FACTORY_TYPE enumeration

## Description

Specifies the type of DirectWrite factory object.

## Constants

### `DWRITE_FACTORY_TYPE_SHARED`

Indicates that the DirectWrite factory is a shared factory and that it allows for the reuse of cached font data across multiple in-process components. Such factories also take advantage of cross process font caching components for better performance.

### `DWRITE_FACTORY_TYPE_ISOLATED`

Indicates that the DirectWrite factory object is isolated. Objects created from the isolated factory do not interact with internal DirectWrite state from other components.

## Remarks

A DirectWrite factory object contains information about its internal state, such as font loader registration and cached font data. In most cases you should use the shared factory object, because it allows multiple components that use DirectWrite to share internal DirectWrite state information, thereby reducing memory usage. However, there are cases when it is desirable to reduce the impact of a component on the rest of the process, such as a plug-in from an untrusted source, by sandboxing and isolating it from the rest of the process components. In such cases, you should use an isolated factory for the sandboxed component.