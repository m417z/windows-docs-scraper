typedef struct _EVENT_PROPERTY_INFO {
  PROPERTY_FLAGS Flags;
  ULONG          NameOffset;
  union {
    struct {
      USHORT InType;
      USHORT OutType;
      ULONG  MapNameOffset;
    } nonStructType;
    struct {
      USHORT StructStartIndex;
      USHORT NumOfStructMembers;
      ULONG  padding;
    } structType;
    struct {
      USHORT InType;
      USHORT OutType;
      ULONG  CustomSchemaOffset;
    } customSchemaType;
  };
  union {
    USHORT count;
    USHORT countPropertyIndex;
  };
  union {
    USHORT length;
    USHORT lengthPropertyIndex;
  };
  union {
    ULONG Reserved;
    struct {
      ULONG Tags : 28;
    };
  };
} EVENT_PROPERTY_INFO;