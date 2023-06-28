FROM gcc:11.3.0
COPY  src/ src/
WORKDIR /src
RUN make
RUN chmod +x ./start.sh
CMD ["./start.sh"]
