FROM gcc:11.3.0
COPY  src/ src/
COPY  start.sh  .
RUN make -C /src
RUN chmod +x ./start.sh
CMD ["./start.sh"]
