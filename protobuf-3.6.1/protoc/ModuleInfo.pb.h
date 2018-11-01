// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ModuleInfo.proto

#ifndef PROTOBUF_INCLUDED_ModuleInfo_2eproto
#define PROTOBUF_INCLUDED_ModuleInfo_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_ModuleInfo_2eproto 

namespace protobuf_ModuleInfo_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_ModuleInfo_2eproto
namespace CMSGProto {
class module_info_reply;
class module_info_replyDefaultTypeInternal;
extern module_info_replyDefaultTypeInternal _module_info_reply_default_instance_;
class module_info_req;
class module_info_reqDefaultTypeInternal;
extern module_info_reqDefaultTypeInternal _module_info_req_default_instance_;
}  // namespace CMSGProto
namespace google {
namespace protobuf {
template<> ::CMSGProto::module_info_reply* Arena::CreateMaybeMessage<::CMSGProto::module_info_reply>(Arena*);
template<> ::CMSGProto::module_info_req* Arena::CreateMaybeMessage<::CMSGProto::module_info_req>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace CMSGProto {

// ===================================================================

class module_info_req : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:CMSGProto.module_info_req) */ {
 public:
  module_info_req();
  virtual ~module_info_req();

  module_info_req(const module_info_req& from);

  inline module_info_req& operator=(const module_info_req& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  module_info_req(module_info_req&& from) noexcept
    : module_info_req() {
    *this = ::std::move(from);
  }

  inline module_info_req& operator=(module_info_req&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const module_info_req& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const module_info_req* internal_default_instance() {
    return reinterpret_cast<const module_info_req*>(
               &_module_info_req_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(module_info_req* other);
  friend void swap(module_info_req& a, module_info_req& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline module_info_req* New() const final {
    return CreateMaybeMessage<module_info_req>(NULL);
  }

  module_info_req* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<module_info_req>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const module_info_req& from);
  void MergeFrom(const module_info_req& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(module_info_req* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string pc_id = 1;
  bool has_pc_id() const;
  void clear_pc_id();
  static const int kPcIdFieldNumber = 1;
  const ::std::string& pc_id() const;
  void set_pc_id(const ::std::string& value);
  #if LANG_CXX11
  void set_pc_id(::std::string&& value);
  #endif
  void set_pc_id(const char* value);
  void set_pc_id(const char* value, size_t size);
  ::std::string* mutable_pc_id();
  ::std::string* release_pc_id();
  void set_allocated_pc_id(::std::string* pc_id);

  // required string file_name = 3;
  bool has_file_name() const;
  void clear_file_name();
  static const int kFileNameFieldNumber = 3;
  const ::std::string& file_name() const;
  void set_file_name(const ::std::string& value);
  #if LANG_CXX11
  void set_file_name(::std::string&& value);
  #endif
  void set_file_name(const char* value);
  void set_file_name(const char* value, size_t size);
  ::std::string* mutable_file_name();
  ::std::string* release_file_name();
  void set_allocated_file_name(::std::string* file_name);

  // required string func_name = 4;
  bool has_func_name() const;
  void clear_func_name();
  static const int kFuncNameFieldNumber = 4;
  const ::std::string& func_name() const;
  void set_func_name(const ::std::string& value);
  #if LANG_CXX11
  void set_func_name(::std::string&& value);
  #endif
  void set_func_name(const char* value);
  void set_func_name(const char* value, size_t size);
  ::std::string* mutable_func_name();
  ::std::string* release_func_name();
  void set_allocated_func_name(::std::string* func_name);

  // required string machine_name = 6;
  bool has_machine_name() const;
  void clear_machine_name();
  static const int kMachineNameFieldNumber = 6;
  const ::std::string& machine_name() const;
  void set_machine_name(const ::std::string& value);
  #if LANG_CXX11
  void set_machine_name(::std::string&& value);
  #endif
  void set_machine_name(const char* value);
  void set_machine_name(const char* value, size_t size);
  ::std::string* mutable_machine_name();
  ::std::string* release_machine_name();
  void set_allocated_machine_name(::std::string* machine_name);

  // required string time = 7;
  bool has_time() const;
  void clear_time();
  static const int kTimeFieldNumber = 7;
  const ::std::string& time() const;
  void set_time(const ::std::string& value);
  #if LANG_CXX11
  void set_time(::std::string&& value);
  #endif
  void set_time(const char* value);
  void set_time(const char* value, size_t size);
  ::std::string* mutable_time();
  ::std::string* release_time();
  void set_allocated_time(::std::string* time);

  // required int32 app_id = 2;
  bool has_app_id() const;
  void clear_app_id();
  static const int kAppIdFieldNumber = 2;
  ::google::protobuf::int32 app_id() const;
  void set_app_id(::google::protobuf::int32 value);

  // required int32 line = 5;
  bool has_line() const;
  void clear_line();
  static const int kLineFieldNumber = 5;
  ::google::protobuf::int32 line() const;
  void set_line(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:CMSGProto.module_info_req)
 private:
  void set_has_pc_id();
  void clear_has_pc_id();
  void set_has_app_id();
  void clear_has_app_id();
  void set_has_file_name();
  void clear_has_file_name();
  void set_has_func_name();
  void clear_has_func_name();
  void set_has_line();
  void clear_has_line();
  void set_has_machine_name();
  void clear_has_machine_name();
  void set_has_time();
  void clear_has_time();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr pc_id_;
  ::google::protobuf::internal::ArenaStringPtr file_name_;
  ::google::protobuf::internal::ArenaStringPtr func_name_;
  ::google::protobuf::internal::ArenaStringPtr machine_name_;
  ::google::protobuf::internal::ArenaStringPtr time_;
  ::google::protobuf::int32 app_id_;
  ::google::protobuf::int32 line_;
  friend struct ::protobuf_ModuleInfo_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class module_info_reply : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:CMSGProto.module_info_reply) */ {
 public:
  module_info_reply();
  virtual ~module_info_reply();

  module_info_reply(const module_info_reply& from);

  inline module_info_reply& operator=(const module_info_reply& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  module_info_reply(module_info_reply&& from) noexcept
    : module_info_reply() {
    *this = ::std::move(from);
  }

  inline module_info_reply& operator=(module_info_reply&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const module_info_reply& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const module_info_reply* internal_default_instance() {
    return reinterpret_cast<const module_info_reply*>(
               &_module_info_reply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(module_info_reply* other);
  friend void swap(module_info_reply& a, module_info_reply& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline module_info_reply* New() const final {
    return CreateMaybeMessage<module_info_reply>(NULL);
  }

  module_info_reply* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<module_info_reply>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const module_info_reply& from);
  void MergeFrom(const module_info_reply& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(module_info_reply* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 reply = 1;
  bool has_reply() const;
  void clear_reply();
  static const int kReplyFieldNumber = 1;
  ::google::protobuf::int32 reply() const;
  void set_reply(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:CMSGProto.module_info_reply)
 private:
  void set_has_reply();
  void clear_has_reply();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::int32 reply_;
  friend struct ::protobuf_ModuleInfo_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// module_info_req

// required string pc_id = 1;
inline bool module_info_req::has_pc_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void module_info_req::set_has_pc_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void module_info_req::clear_has_pc_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void module_info_req::clear_pc_id() {
  pc_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_pc_id();
}
inline const ::std::string& module_info_req::pc_id() const {
  // @@protoc_insertion_point(field_get:CMSGProto.module_info_req.pc_id)
  return pc_id_.GetNoArena();
}
inline void module_info_req::set_pc_id(const ::std::string& value) {
  set_has_pc_id();
  pc_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:CMSGProto.module_info_req.pc_id)
}
#if LANG_CXX11
inline void module_info_req::set_pc_id(::std::string&& value) {
  set_has_pc_id();
  pc_id_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:CMSGProto.module_info_req.pc_id)
}
#endif
inline void module_info_req::set_pc_id(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_pc_id();
  pc_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:CMSGProto.module_info_req.pc_id)
}
inline void module_info_req::set_pc_id(const char* value, size_t size) {
  set_has_pc_id();
  pc_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:CMSGProto.module_info_req.pc_id)
}
inline ::std::string* module_info_req::mutable_pc_id() {
  set_has_pc_id();
  // @@protoc_insertion_point(field_mutable:CMSGProto.module_info_req.pc_id)
  return pc_id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* module_info_req::release_pc_id() {
  // @@protoc_insertion_point(field_release:CMSGProto.module_info_req.pc_id)
  if (!has_pc_id()) {
    return NULL;
  }
  clear_has_pc_id();
  return pc_id_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void module_info_req::set_allocated_pc_id(::std::string* pc_id) {
  if (pc_id != NULL) {
    set_has_pc_id();
  } else {
    clear_has_pc_id();
  }
  pc_id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), pc_id);
  // @@protoc_insertion_point(field_set_allocated:CMSGProto.module_info_req.pc_id)
}

// required int32 app_id = 2;
inline bool module_info_req::has_app_id() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void module_info_req::set_has_app_id() {
  _has_bits_[0] |= 0x00000020u;
}
inline void module_info_req::clear_has_app_id() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void module_info_req::clear_app_id() {
  app_id_ = 0;
  clear_has_app_id();
}
inline ::google::protobuf::int32 module_info_req::app_id() const {
  // @@protoc_insertion_point(field_get:CMSGProto.module_info_req.app_id)
  return app_id_;
}
inline void module_info_req::set_app_id(::google::protobuf::int32 value) {
  set_has_app_id();
  app_id_ = value;
  // @@protoc_insertion_point(field_set:CMSGProto.module_info_req.app_id)
}

// required string file_name = 3;
inline bool module_info_req::has_file_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void module_info_req::set_has_file_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void module_info_req::clear_has_file_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void module_info_req::clear_file_name() {
  file_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_file_name();
}
inline const ::std::string& module_info_req::file_name() const {
  // @@protoc_insertion_point(field_get:CMSGProto.module_info_req.file_name)
  return file_name_.GetNoArena();
}
inline void module_info_req::set_file_name(const ::std::string& value) {
  set_has_file_name();
  file_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:CMSGProto.module_info_req.file_name)
}
#if LANG_CXX11
inline void module_info_req::set_file_name(::std::string&& value) {
  set_has_file_name();
  file_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:CMSGProto.module_info_req.file_name)
}
#endif
inline void module_info_req::set_file_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_file_name();
  file_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:CMSGProto.module_info_req.file_name)
}
inline void module_info_req::set_file_name(const char* value, size_t size) {
  set_has_file_name();
  file_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:CMSGProto.module_info_req.file_name)
}
inline ::std::string* module_info_req::mutable_file_name() {
  set_has_file_name();
  // @@protoc_insertion_point(field_mutable:CMSGProto.module_info_req.file_name)
  return file_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* module_info_req::release_file_name() {
  // @@protoc_insertion_point(field_release:CMSGProto.module_info_req.file_name)
  if (!has_file_name()) {
    return NULL;
  }
  clear_has_file_name();
  return file_name_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void module_info_req::set_allocated_file_name(::std::string* file_name) {
  if (file_name != NULL) {
    set_has_file_name();
  } else {
    clear_has_file_name();
  }
  file_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), file_name);
  // @@protoc_insertion_point(field_set_allocated:CMSGProto.module_info_req.file_name)
}

// required string func_name = 4;
inline bool module_info_req::has_func_name() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void module_info_req::set_has_func_name() {
  _has_bits_[0] |= 0x00000004u;
}
inline void module_info_req::clear_has_func_name() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void module_info_req::clear_func_name() {
  func_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_func_name();
}
inline const ::std::string& module_info_req::func_name() const {
  // @@protoc_insertion_point(field_get:CMSGProto.module_info_req.func_name)
  return func_name_.GetNoArena();
}
inline void module_info_req::set_func_name(const ::std::string& value) {
  set_has_func_name();
  func_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:CMSGProto.module_info_req.func_name)
}
#if LANG_CXX11
inline void module_info_req::set_func_name(::std::string&& value) {
  set_has_func_name();
  func_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:CMSGProto.module_info_req.func_name)
}
#endif
inline void module_info_req::set_func_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_func_name();
  func_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:CMSGProto.module_info_req.func_name)
}
inline void module_info_req::set_func_name(const char* value, size_t size) {
  set_has_func_name();
  func_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:CMSGProto.module_info_req.func_name)
}
inline ::std::string* module_info_req::mutable_func_name() {
  set_has_func_name();
  // @@protoc_insertion_point(field_mutable:CMSGProto.module_info_req.func_name)
  return func_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* module_info_req::release_func_name() {
  // @@protoc_insertion_point(field_release:CMSGProto.module_info_req.func_name)
  if (!has_func_name()) {
    return NULL;
  }
  clear_has_func_name();
  return func_name_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void module_info_req::set_allocated_func_name(::std::string* func_name) {
  if (func_name != NULL) {
    set_has_func_name();
  } else {
    clear_has_func_name();
  }
  func_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), func_name);
  // @@protoc_insertion_point(field_set_allocated:CMSGProto.module_info_req.func_name)
}

// required int32 line = 5;
inline bool module_info_req::has_line() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void module_info_req::set_has_line() {
  _has_bits_[0] |= 0x00000040u;
}
inline void module_info_req::clear_has_line() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void module_info_req::clear_line() {
  line_ = 0;
  clear_has_line();
}
inline ::google::protobuf::int32 module_info_req::line() const {
  // @@protoc_insertion_point(field_get:CMSGProto.module_info_req.line)
  return line_;
}
inline void module_info_req::set_line(::google::protobuf::int32 value) {
  set_has_line();
  line_ = value;
  // @@protoc_insertion_point(field_set:CMSGProto.module_info_req.line)
}

// required string machine_name = 6;
inline bool module_info_req::has_machine_name() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void module_info_req::set_has_machine_name() {
  _has_bits_[0] |= 0x00000008u;
}
inline void module_info_req::clear_has_machine_name() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void module_info_req::clear_machine_name() {
  machine_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_machine_name();
}
inline const ::std::string& module_info_req::machine_name() const {
  // @@protoc_insertion_point(field_get:CMSGProto.module_info_req.machine_name)
  return machine_name_.GetNoArena();
}
inline void module_info_req::set_machine_name(const ::std::string& value) {
  set_has_machine_name();
  machine_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:CMSGProto.module_info_req.machine_name)
}
#if LANG_CXX11
inline void module_info_req::set_machine_name(::std::string&& value) {
  set_has_machine_name();
  machine_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:CMSGProto.module_info_req.machine_name)
}
#endif
inline void module_info_req::set_machine_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_machine_name();
  machine_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:CMSGProto.module_info_req.machine_name)
}
inline void module_info_req::set_machine_name(const char* value, size_t size) {
  set_has_machine_name();
  machine_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:CMSGProto.module_info_req.machine_name)
}
inline ::std::string* module_info_req::mutable_machine_name() {
  set_has_machine_name();
  // @@protoc_insertion_point(field_mutable:CMSGProto.module_info_req.machine_name)
  return machine_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* module_info_req::release_machine_name() {
  // @@protoc_insertion_point(field_release:CMSGProto.module_info_req.machine_name)
  if (!has_machine_name()) {
    return NULL;
  }
  clear_has_machine_name();
  return machine_name_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void module_info_req::set_allocated_machine_name(::std::string* machine_name) {
  if (machine_name != NULL) {
    set_has_machine_name();
  } else {
    clear_has_machine_name();
  }
  machine_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), machine_name);
  // @@protoc_insertion_point(field_set_allocated:CMSGProto.module_info_req.machine_name)
}

// required string time = 7;
inline bool module_info_req::has_time() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void module_info_req::set_has_time() {
  _has_bits_[0] |= 0x00000010u;
}
inline void module_info_req::clear_has_time() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void module_info_req::clear_time() {
  time_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_time();
}
inline const ::std::string& module_info_req::time() const {
  // @@protoc_insertion_point(field_get:CMSGProto.module_info_req.time)
  return time_.GetNoArena();
}
inline void module_info_req::set_time(const ::std::string& value) {
  set_has_time();
  time_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:CMSGProto.module_info_req.time)
}
#if LANG_CXX11
inline void module_info_req::set_time(::std::string&& value) {
  set_has_time();
  time_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:CMSGProto.module_info_req.time)
}
#endif
inline void module_info_req::set_time(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_time();
  time_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:CMSGProto.module_info_req.time)
}
inline void module_info_req::set_time(const char* value, size_t size) {
  set_has_time();
  time_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:CMSGProto.module_info_req.time)
}
inline ::std::string* module_info_req::mutable_time() {
  set_has_time();
  // @@protoc_insertion_point(field_mutable:CMSGProto.module_info_req.time)
  return time_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* module_info_req::release_time() {
  // @@protoc_insertion_point(field_release:CMSGProto.module_info_req.time)
  if (!has_time()) {
    return NULL;
  }
  clear_has_time();
  return time_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void module_info_req::set_allocated_time(::std::string* time) {
  if (time != NULL) {
    set_has_time();
  } else {
    clear_has_time();
  }
  time_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), time);
  // @@protoc_insertion_point(field_set_allocated:CMSGProto.module_info_req.time)
}

// -------------------------------------------------------------------

// module_info_reply

// required int32 reply = 1;
inline bool module_info_reply::has_reply() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void module_info_reply::set_has_reply() {
  _has_bits_[0] |= 0x00000001u;
}
inline void module_info_reply::clear_has_reply() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void module_info_reply::clear_reply() {
  reply_ = 0;
  clear_has_reply();
}
inline ::google::protobuf::int32 module_info_reply::reply() const {
  // @@protoc_insertion_point(field_get:CMSGProto.module_info_reply.reply)
  return reply_;
}
inline void module_info_reply::set_reply(::google::protobuf::int32 value) {
  set_has_reply();
  reply_ = value;
  // @@protoc_insertion_point(field_set:CMSGProto.module_info_reply.reply)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace CMSGProto

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_ModuleInfo_2eproto
