# 2lru-for-ccnsim
This Class implements 2lRU a caching replacement algorithm proposed by Garetto et al [1] for ccnsim that is a simulator for Content Centric Networks [2]. 

Copy k2lru.h to ccnsim/include/ \
Copy k2lru.cc to ccnsim/src/noce/cache/ \
Copy cache.ned to ccnsim/modules/node/cache/ \
Copy Makefile to ccnsim/ \ 

Make the poroject before run it.

Note: this class in compatible with ccnsim3.

[1] M. Garetto, E. Leonardi, and V. Martina. A Unified Approach to the Performance Analysis of Caching Systems. ACM Transactions on Modeling and Performance Evaluation of Computing Systems, 1(3):12:1–12:28, May 2016
[2] G. Rossini and D. Rossi, “ccnSim: an highly scalable CCN simulator,” in IEEE ICC, 2013.
