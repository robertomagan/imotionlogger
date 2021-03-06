// THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
// BY HAND!!
//
// Generated by lcm-gen

#include <string.h>
#include "lcmtypes/poselcm_pose_t.h"

static int __poselcm_pose_t_hash_computed;
static int64_t __poselcm_pose_t_hash;

int64_t __poselcm_pose_t_hash_recursive(const __lcm_hash_ptr *p)
{
    const __lcm_hash_ptr *fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __poselcm_pose_t_get_hash)
            return 0;

    __lcm_hash_ptr cp;
    cp.parent =  p;
    cp.v = (void*)__poselcm_pose_t_get_hash;
    (void) cp;

    int64_t hash = (int64_t)0x0ecda64b9b709dc0LL
         + __byte_hash_recursive(&cp)
         + __int16_t_hash_recursive(&cp)
         + __int16_t_hash_recursive(&cp)
         + __int16_t_hash_recursive(&cp)
        ;

    return (hash<<1) + ((hash>>63)&1);
}

int64_t __poselcm_pose_t_get_hash(void)
{
    if (!__poselcm_pose_t_hash_computed) {
        __poselcm_pose_t_hash = __poselcm_pose_t_hash_recursive(NULL);
        __poselcm_pose_t_hash_computed = 1;
    }

    return __poselcm_pose_t_hash;
}

int __poselcm_pose_t_encode_array(void *buf, int offset, int maxlen, const poselcm_pose_t *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __byte_encode_array(buf, offset + pos, maxlen - pos, &(p[element].robotid), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_encode_array(buf, offset + pos, maxlen - pos, p[element].position, 3);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_encode_array(buf, offset + pos, maxlen - pos, p[element].orientation, 4);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].velocity), 1);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int poselcm_pose_t_encode(void *buf, int offset, int maxlen, const poselcm_pose_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __poselcm_pose_t_get_hash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    thislen = __poselcm_pose_t_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int __poselcm_pose_t_encoded_array_size(const poselcm_pose_t *p, int elements)
{
    int size = 0, element;
    for (element = 0; element < elements; element++) {

        size += __byte_encoded_array_size(&(p[element].robotid), 1);

        size += __int16_t_encoded_array_size(p[element].position, 3);

        size += __int16_t_encoded_array_size(p[element].orientation, 4);

        size += __int16_t_encoded_array_size(&(p[element].velocity), 1);

    }
    return size;
}

int poselcm_pose_t_encoded_size(const poselcm_pose_t *p)
{
    return 8 + __poselcm_pose_t_encoded_array_size(p, 1);
}

int __poselcm_pose_t_decode_array(const void *buf, int offset, int maxlen, poselcm_pose_t *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __byte_decode_array(buf, offset + pos, maxlen - pos, &(p[element].robotid), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_decode_array(buf, offset + pos, maxlen - pos, p[element].position, 3);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_decode_array(buf, offset + pos, maxlen - pos, p[element].orientation, 4);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].velocity), 1);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int __poselcm_pose_t_decode_array_cleanup(poselcm_pose_t *p, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __byte_decode_array_cleanup(&(p[element].robotid), 1);

        __int16_t_decode_array_cleanup(p[element].position, 3);

        __int16_t_decode_array_cleanup(p[element].orientation, 4);

        __int16_t_decode_array_cleanup(&(p[element].velocity), 1);

    }
    return 0;
}

int poselcm_pose_t_decode(const void *buf, int offset, int maxlen, poselcm_pose_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __poselcm_pose_t_get_hash();

    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;

    thislen = __poselcm_pose_t_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int poselcm_pose_t_decode_cleanup(poselcm_pose_t *p)
{
    return __poselcm_pose_t_decode_array_cleanup(p, 1);
}

int __poselcm_pose_t_clone_array(const poselcm_pose_t *p, poselcm_pose_t *q, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __byte_clone_array(&(p[element].robotid), &(q[element].robotid), 1);

        __int16_t_clone_array(p[element].position, q[element].position, 3);

        __int16_t_clone_array(p[element].orientation, q[element].orientation, 4);

        __int16_t_clone_array(&(p[element].velocity), &(q[element].velocity), 1);

    }
    return 0;
}

poselcm_pose_t *poselcm_pose_t_copy(const poselcm_pose_t *p)
{
    poselcm_pose_t *q = (poselcm_pose_t*) malloc(sizeof(poselcm_pose_t));
    __poselcm_pose_t_clone_array(p, q, 1);
    return q;
}

void poselcm_pose_t_destroy(poselcm_pose_t *p)
{
    __poselcm_pose_t_decode_array_cleanup(p, 1);
    free(p);
}

int poselcm_pose_t_publish(lcm_t *lc, const char *channel, const poselcm_pose_t *p)
{
      int max_data_size = poselcm_pose_t_encoded_size (p);
      uint8_t *buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = poselcm_pose_t_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = lcm_publish (lc, channel, buf, data_size);
      free (buf);
      return status;
}

struct _poselcm_pose_t_subscription_t {
    poselcm_pose_t_handler_t user_handler;
    void *userdata;
    lcm_subscription_t *lc_h;
};
static
void poselcm_pose_t_handler_stub (const lcm_recv_buf_t *rbuf,
                            const char *channel, void *userdata)
{
    int status;
    poselcm_pose_t p;
    memset(&p, 0, sizeof(poselcm_pose_t));
    status = poselcm_pose_t_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        fprintf (stderr, "error %d decoding poselcm_pose_t!!!\n", status);
        return;
    }

    poselcm_pose_t_subscription_t *h = (poselcm_pose_t_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    poselcm_pose_t_decode_cleanup (&p);
}

poselcm_pose_t_subscription_t* poselcm_pose_t_subscribe (lcm_t *lcm,
                    const char *channel,
                    poselcm_pose_t_handler_t f, void *userdata)
{
    poselcm_pose_t_subscription_t *n = (poselcm_pose_t_subscription_t*)
                       malloc(sizeof(poselcm_pose_t_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->lc_h = lcm_subscribe (lcm, channel,
                                 poselcm_pose_t_handler_stub, n);
    if (n->lc_h == NULL) {
        fprintf (stderr,"couldn't reg poselcm_pose_t LCM handler!\n");
        free (n);
        return NULL;
    }
    return n;
}

int poselcm_pose_t_subscription_set_queue_capacity (poselcm_pose_t_subscription_t* subs,
                              int num_messages)
{
    return lcm_subscription_set_queue_capacity (subs->lc_h, num_messages);
}

int poselcm_pose_t_unsubscribe(lcm_t *lcm, poselcm_pose_t_subscription_t* hid)
{
    int status = lcm_unsubscribe (lcm, hid->lc_h);
    if (0 != status) {
        fprintf(stderr,
           "couldn't unsubscribe poselcm_pose_t_handler %p!\n", hid);
        return -1;
    }
    free (hid);
    return 0;
}

