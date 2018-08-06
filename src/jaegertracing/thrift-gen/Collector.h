/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Collector_H
#define Collector_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "jaeger_types.h"

namespace jaegertracing { namespace thrift {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class CollectorIf {
 public:
  virtual ~CollectorIf() {}
  virtual void submitBatches(std::vector<BatchSubmitResponse> & _return, const std::vector<Batch> & batches) = 0;
};

class CollectorIfFactory {
 public:
  typedef CollectorIf Handler;

  virtual ~CollectorIfFactory() {}

  virtual CollectorIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(CollectorIf* /* handler */) = 0;
};

class CollectorIfSingletonFactory : virtual public CollectorIfFactory {
 public:
  CollectorIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<CollectorIf>& iface) : iface_(iface) {}
  virtual ~CollectorIfSingletonFactory() {}

  virtual CollectorIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(CollectorIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<CollectorIf> iface_;
};

class CollectorNull : virtual public CollectorIf {
 public:
  virtual ~CollectorNull() {}
  void submitBatches(std::vector<BatchSubmitResponse> & /* _return */, const std::vector<Batch> & /* batches */) {
    return;
  }
};

typedef struct _Collector_submitBatches_args__isset {
  _Collector_submitBatches_args__isset() : batches(false) {}
  bool batches :1;
} _Collector_submitBatches_args__isset;

class Collector_submitBatches_args {
 public:

  Collector_submitBatches_args(const Collector_submitBatches_args&);
  Collector_submitBatches_args& operator=(const Collector_submitBatches_args&);
  Collector_submitBatches_args() {
  }

  virtual ~Collector_submitBatches_args() throw();
  std::vector<Batch>  batches;

  _Collector_submitBatches_args__isset __isset;

  void __set_batches(const std::vector<Batch> & val);

  bool operator == (const Collector_submitBatches_args & rhs) const
  {
    if (!(batches == rhs.batches))
      return false;
    return true;
  }
  bool operator != (const Collector_submitBatches_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Collector_submitBatches_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Collector_submitBatches_pargs {
 public:


  virtual ~Collector_submitBatches_pargs() throw();
  const std::vector<Batch> * batches;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Collector_submitBatches_result__isset {
  _Collector_submitBatches_result__isset() : success(false) {}
  bool success :1;
} _Collector_submitBatches_result__isset;

class Collector_submitBatches_result {
 public:

  Collector_submitBatches_result(const Collector_submitBatches_result&);
  Collector_submitBatches_result& operator=(const Collector_submitBatches_result&);
  Collector_submitBatches_result() {
  }

  virtual ~Collector_submitBatches_result() throw();
  std::vector<BatchSubmitResponse>  success;

  _Collector_submitBatches_result__isset __isset;

  void __set_success(const std::vector<BatchSubmitResponse> & val);

  bool operator == (const Collector_submitBatches_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Collector_submitBatches_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Collector_submitBatches_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Collector_submitBatches_presult__isset {
  _Collector_submitBatches_presult__isset() : success(false) {}
  bool success :1;
} _Collector_submitBatches_presult__isset;

class Collector_submitBatches_presult {
 public:


  virtual ~Collector_submitBatches_presult() throw();
  std::vector<BatchSubmitResponse> * success;

  _Collector_submitBatches_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class CollectorClient : virtual public CollectorIf {
 public:
  CollectorClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  CollectorClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void submitBatches(std::vector<BatchSubmitResponse> & _return, const std::vector<Batch> & batches);
  void send_submitBatches(const std::vector<Batch> & batches);
  void recv_submitBatches(std::vector<BatchSubmitResponse> & _return);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class CollectorProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<CollectorIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (CollectorProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_submitBatches(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  CollectorProcessor(::apache::thrift::stdcxx::shared_ptr<CollectorIf> iface) :
    iface_(iface) {
    processMap_["submitBatches"] = &CollectorProcessor::process_submitBatches;
  }

  virtual ~CollectorProcessor() {}
};

class CollectorProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  CollectorProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< CollectorIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< CollectorIfFactory > handlerFactory_;
};

class CollectorMultiface : virtual public CollectorIf {
 public:
  CollectorMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<CollectorIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~CollectorMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<CollectorIf> > ifaces_;
  CollectorMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<CollectorIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void submitBatches(std::vector<BatchSubmitResponse> & _return, const std::vector<Batch> & batches) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->submitBatches(_return, batches);
    }
    ifaces_[i]->submitBatches(_return, batches);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class CollectorConcurrentClient : virtual public CollectorIf {
 public:
  CollectorConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  CollectorConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void submitBatches(std::vector<BatchSubmitResponse> & _return, const std::vector<Batch> & batches);
  int32_t send_submitBatches(const std::vector<Batch> & batches);
  void recv_submitBatches(std::vector<BatchSubmitResponse> & _return, const int32_t seqid);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

}} // namespace

#endif
