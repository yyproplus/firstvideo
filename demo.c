#include<stdio.h>

#include "libavformat\avformat.h"
#include "libavcodec\avcodec.h"
#include "libavcodec\codec.h"
#include "libavutil\frame.h"
#include "libavcodec\packet.h"
#include "libswscale\swscale_internal.h"
int main()
{
    
    AVFormatContext *pFormatCtx;
    AVCodecContext  *pCodecCtx;
    AVCodec         *pCodec;
    int	             i, videoindex;
    AVFrame *pFrame,*pFrameYUV;
    AVPacket *packet;
    int screen_w,screen_h;


    FILE *fp_yuv;
    int ret,got_picture;
    char filepath[]="bigbuckbunny_480x272.h265";
    av_register_all();
    avformat_network_init();

    pFormatCtx=avformat_alloc_context();
    if(avformat_open_input(&pFormatCtx,filepath,NULL,NULL)<0){
        printf("Couldn't find stream information.\n");
        return -1;
    }
    videoindex=-1;
    for(i=0;i<pFormatCtx->nb_streams;i++){
        if(pFormatCtx->streams[i]->codec_type==AVMDIA_TYPE_VIDEO){
            videoindex=i;
            break;
        }
    }
    if(videoindex==-1){
        printf("Didn't find a video stream\n");
        return -1;
    }
    pCodeCtx=pFormatCtx->streams[videoindex]->codec;
}